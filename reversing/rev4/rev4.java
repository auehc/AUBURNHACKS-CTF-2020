
import java.io.*;
import java.util.Scanner;

public class rev4 {

    public static void main(String[] args) {

        System.out.println("Feed me!");

        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        scanner.close();

        boolean pass = encrypt(input);

        if (pass) {
            read_file();
        }
    }

    private static boolean encrypt(String input) {

        int secret[] = { 0x03, 0x19, 0x03, 0x07, 0x0e, 0x0a, 0x10, 0x1b };

        String key = "aubie";
        if (secret.length == input.length()) {
            for (int i = 0; i < secret.length; i++) {
                int out = input.charAt(i) ^ key.charAt(i % key.length());
                if (out != secret[i]) {
                    return false;
                }
            }

            return true;
        }
        System.out.println("Wrong!");
        return false;
    }

    private static void read_file() {
        String filename = "flag.txt";
        try (BufferedReader br = new BufferedReader(new FileReader(filename))) {
            String line;
            while ((line = br.readLine()) != null) {
                System.out.println(line);
            }

        } catch (IOException ex) {
            System.out.println("Could not find file please notify admin");
        }
    }
}
