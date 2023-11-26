// Para la segunda etapa, puedes agregar menús y barras de herramientas utilizando JMenuBar y JToolBar.
// Además, puedes usar AbstractAction para gestionar las acciones y evitar duplicar código.

// Ejemplo:
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;

public class RemoteControl extends JFrame {
    private static final long serialVersionUID = 1L;
    private JTextArea textArea;

    public RemoteControl() {
        // ... (código anterior)

        // Crear barra de menú y menú desplegable
        JMenuBar menuBar = new JMenuBar();
        JMenu fileMenu = new JMenu("File");

        // Crear acciones para los botones de menú
        Action button1Action = new AbstractAction("Button 1") {
            @Override
            public void actionPerformed(ActionEvent e) {
                textArea.append("Button 1 pressed\n");
            }
        };

        Action button2Action = new AbstractAction("Button 2") {
            @Override
            public void actionPerformed(ActionEvent e) {
                textArea.append("Button 2 pressed\n");
            }
        };

        Action exitAction = new AbstractAction("Exit") {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        };

        // Agregar acciones a los elementos del menú
        fileMenu.add(new JMenuItem(button1Action));
        fileMenu.add(new JMenuItem(button2Action));
        fileMenu.addSeparator();
        fileMenu.add(new JMenuItem(exitAction));

        // Agregar menú desplegable a la barra de menú
        menuBar.add(fileMenu);

        // Configurar la barra de menú en el JFrame
        setJMenuBar(menuBar);
    }

    // ... (resto del código)
}
