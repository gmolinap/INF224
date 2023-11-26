// Para la tercera etapa, puedes usar la clase Socket para interactuar con el servidor C++.

// Ejemplo simple para establecer una conexión con el servidor:
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

public class Client {
    public static void main(String[] args) {
        try {
            // Establecer conexión con el servidor en el puerto 3331
            Socket socket = new Socket("localhost", 3331);

            // Configurar canales de entrada y salida
            BufferedReader input = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            PrintWriter output = new PrintWriter(socket.getOutputStream(), true);

            // Enviar solicitud al servidor
            output.println("find Photo_0");

            // Recibir respuesta del servidor
            String response = input.readLine();
            System.out.println("Server response: " + response);

            // Cerrar la conexión
            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
