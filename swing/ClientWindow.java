import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.Socket;
import java.net.UnknownHostException;

import javax.swing.AbstractAction;
import javax.swing.Action;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.JToolBar;
import javax.swing.SwingUtilities;

public class ClientWindow extends JFrame {
    private static final long serialVersionUID = 1L;
    private JTextArea textArea;
    private JMenuBar menuBar;
    private JMenu menu;
    private JToolBar toolBar;
    private JTextField textField;
    private JLabel label;
    private JPanel panel;

    private static final String DEFAULT_HOST = "localhost";
    private static final int DEFAULT_PORT = 3331;
    private static String host = DEFAULT_HOST;
    private static int port = DEFAULT_PORT;
    private static Client client = null;

    public ClientWindow() {
        super("Client Window");
        setLayout(new BorderLayout());
        textArea = new JTextArea(20, 60);
        textArea.setEditable(false);

        panel = new JPanel(new BorderLayout());
        label = new JLabel("Enter your media/group name:");
        textField = new JTextField(60);
        panel.add(label, BorderLayout.NORTH);
        panel.add(textField, BorderLayout.SOUTH);
        add(panel, BorderLayout.SOUTH);

        menuBar = new JMenuBar();
        menu = new JMenu("Menu");
        setJMenuBar(menuBar);
        menuBar.add(menu);

        Action connectAction = new ConnectAction();
        Action findAction = new FindAction();
        Action displayMediaAction = new DisplayMediaAction();
        Action displayGroupAction = new DisplayGroupAction();
        Action reproduceAction = new ReproduceAction();
        Action exitAction = new ExitAction();

        menu.add(new JMenuItem(connectAction));
        menu.add(new JMenuItem(findAction));
        menu.add(new JMenuItem(displayMediaAction));
        menu.add(new JMenuItem(displayGroupAction));
        menu.add(new JMenuItem(reproduceAction));
        menu.addSeparator();
        menu.add(new JMenuItem(exitAction));

        toolBar = new JToolBar();
        toolBar.add(new JButton(connectAction));
        toolBar.add(new JButton(findAction));
        toolBar.add(new JButton(displayMediaAction));
        toolBar.add(new JButton(displayGroupAction));
        toolBar.add(new JButton(reproduceAction));
        toolBar.addSeparator();
        toolBar.add(new JButton(exitAction));
        add(toolBar, BorderLayout.NORTH);

        JScrollPane scrollPane = new JScrollPane(textArea);
        scrollPane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
        scrollPane.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_NEVER);
        add(scrollPane, BorderLayout.CENTER);

        setDefaultCloseOperation(EXIT_ON_CLOSE);
        pack();
        setVisible(true);

        // Redirigir la salida estándar y de error estándar a JTextArea
        RedirectOutputToTextArea.redirectSystemOut(textArea);
        RedirectOutputToTextArea.redirectSystemErr(textArea);
    }

    private class ConnectAction extends AbstractAction {
        public ConnectAction() {
            super("Connect");
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            if (client != null && client.isConnected()) {
                textArea.append("Client already connected to " + host + ":" + port + "\n");
                return;
            }
            try {
                client = new Client(host, port);
                textArea.append("Client connected to " + host + ":" + port + "\n");
            } catch (Exception ex) {
                textArea.append("Client: Couldn't connect to " + host + ":" + port + "\n");
            }
        }
    }

    private class FindAction extends AbstractAction {
        public FindAction() {
            super("Find");
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            String request = "find " + textField.getText();
            String response = client.send(request);
            textArea.append(client.handleResponse(response));
        }
    }

    private class DisplayGroupAction extends AbstractAction {
        public DisplayGroupAction() {
            super("Display Group");
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            String request = "displayGroup " + textField.getText();
            String response = client.send(request);
            textArea.append(client.handleResponse(response));
        }
    }

    private class DisplayMediaAction extends AbstractAction {
        public DisplayMediaAction() {
            super("Display Media");
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            String request = "displayMedia " + textField.getText();
            String response = client.send(request);
            textArea.append(client.handleResponse(response));
        }
    }

    private class ReproduceAction extends AbstractAction {
        public ReproduceAction() {
            super("Reproduce");
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            String request = "reproduce " + textField.getText();
            String response = client.send(request);
            textArea.append(client.handleResponse(response));
        }
    }

    private class ExitAction extends AbstractAction {
        public ExitAction() {
            super("Exit");
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            System.exit(0);
        }
    }

    public static void main(String[] args) {
        if (args.length >= 1)
            host = args[0];
        if (args.length >= 2)
            port = Integer.parseInt(args[1]);

        SwingUtilities.invokeLater(() -> new ClientWindow());
    }

    private static class Client {
        private Socket sock;
        private BufferedReader input;
        private BufferedWriter output;

        public Client(String host, int port) throws UnknownHostException, IOException {
            try {
                sock = new java.net.Socket(host, port);
            } catch (java.net.UnknownHostException e) {
                throw e;
            } catch (java.io.IOException e) {
                throw e;
            }

            try {
                input = new BufferedReader(new InputStreamReader(sock.getInputStream()));
                output = new BufferedWriter(new OutputStreamWriter(sock.getOutputStream()));
            } catch (java.io.IOException e) {
                throw e;
            }
        }

        public String send(String request) {
            try {
                request += "\n";
                output.write(request, 0, request.length());
                output.flush();
            } catch (java.io.IOException e) {
                return null;
            }

            try {
                return input.readLine();
            } catch (java.io.IOException e) {
                return null;
            }
        }

        public String handleResponse(String response) {
            if (response != null) {
                response = response.replace("/end/", "\n");
            }
            return response;
        }

        public boolean isConnected() {
            return sock != null && sock.isConnected() && !sock.isClosed();
        }
    }
}

class RedirectOutputToTextArea {
    public static void redirectSystemOut(JTextArea textArea) {
        System.setOut(new java.io.PrintStream(new java.io.OutputStream() {
            @Override
            public void write(int b) throws IOException {
                textArea.append(String.valueOf((char) b));
                textArea.setCaretPosition(textArea.getDocument().getLength());
            }
        }, true));
    }

    public static void redirectSystemErr(JTextArea textArea) {
        System.setErr(new java.io.PrintStream(new java.io.OutputStream() {
            @Override
            public void write(int b) throws IOException {
                textArea.append(String.valueOf((char) b));
                textArea.setCaretPosition(textArea.getDocument().getLength());
            }
        }, true));
    }
}
