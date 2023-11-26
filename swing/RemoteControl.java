import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class RemoteControl extends JFrame {
    private static final long serialVersionUID = 1L;

    private JTextArea textArea;

    public RemoteControl() {
        // Configuración del JFrame
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        // Configuración del JTextArea en un JScrollPane
        textArea = new JTextArea(10, 30);
        JScrollPane scrollPane = new JScrollPane(textArea);
        add(scrollPane, BorderLayout.CENTER);

        // Configuración de los botones
        JButton button1 = new JButton("Button 1");
        JButton button2 = new JButton("Button 2");
        JButton exitButton = new JButton("Exit");

        // Configuración de acciones para los botones
        button1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                textArea.append("Button 1 pressed\n");
            }
        });

        button2.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                textArea.append("Button 2 pressed\n");
            }
        });

        exitButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });

        // Configuración del contenedor para los botones
        JPanel buttonPanel = new JPanel();
        buttonPanel.add(button1);
        buttonPanel.add(button2);
        buttonPanel.add(exitButton);

        // Agregar el contenedor de botones en la zona sur del JFrame
        add(buttonPanel, BorderLayout.SOUTH);

        // Ajustar la disposición de los componentes y hacer visible la interfaz
        pack();
        setVisible(true);
    }

    public static void main(String[] args) {
        // Establecer el aspecto de la barra de menú en macOS
        System.setProperty("apple.laf.useScreenMenuBar", "true");

        // Crear la interfaz gráfica
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new RemoteControl();
            }
        });
    }
}
