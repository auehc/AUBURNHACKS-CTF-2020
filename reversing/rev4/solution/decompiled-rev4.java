
/*    */ import java.io.BufferedReader;
/*    */ import java.io.FileReader;
/*    */ import java.io.IOException;
/*    */ import java.util.Scanner;

/*    */
/*    */ public class rev4
/*    */ {
    /*    */ public static void main(String[] paramArrayOfString) {
        /* 9 */ Scanner scanner = new Scanner(System.in);
        /* 10 */ String str = scanner.nextLine();
        /*    */
        /* 12 */ boolean bool = encrypt(str);
        /*    */
        /* 14 */ if (bool) {
            /* 15 */ read_file();
            /*    */ }
        /*    */ }

    /*    */
    /*    */
    /*    */ private static boolean encrypt(String paramString) {
        /* 21 */ int[] arrayOfInt = { 3, 25, 3, 7, 14, 10, 16, 27 };
        /*    */
        /* 23 */ String str = "aubie";
        /*    */
        /* 25 */ for (int i = 0; i < paramString.length(); i++) {
            /*    */
            /* 27 */ char c = paramString.charAt(i) ^ str.charAt(i % str.length());
            /* 28 */ if (c != arrayOfInt[i]) {
                /* 29 */ return false;
                /*    */ }
            /*    */ }
        /*    */
        /* 33 */ return true;
        /*    */ }

    /*    */
    /*    */ private static void read_file() {
        /* 37 */ String str = "rev2.flag";
        /* 38 */ try {
            BufferedReader bufferedReader = new BufferedReader(new FileReader(str));
            /*    */ try {
                String str1;
                /* 40 */ while ((str1 = bufferedReader.readLine()) != null) {
                    /* 41 */ System.out.println(str1);
                    /*    */ }
                /*    */
                /* 44 */ bufferedReader.close();
            } catch (Throwable throwable) {
                try {
                    bufferedReader.close();
                } catch (Throwable throwable1) {
                    throwable.addSuppressed(throwable1);
                }
                throw throwable;
            }
        } catch (IOException iOException)
        /* 45 */ {
            System.out.println("Could not find file please notify admin" + str);
        }
        /*    */
        /*    */ }
    /*    */ }

/*
 * Location:
 * /mnt/hgfs/snow/Documents/GitLab/ctf_hacks_20/reversing/rev2/!/rev2.class Java
 * compiler version: 13 (57.0) JD-Core Version: 1.0.7
 */