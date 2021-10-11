import java.util.Random;

public class Problema1 {
    // Esta clase representa el struct en C
    class Array {
        int[] arreglo;

        // IntArray *createIntArray(int size);
        // Este constructor representa la funcion createIntArray
        public Array(int numero) {
            arreglo = new Array(numero);
        }

        // void initIntArray(IntArray *);
        // Este metodo representa la funcion initIntArray
        public void initIntArray() {
            for (int i = 0; i < Array.length; i++) {
                Array[i] = (int)Math.random();
            }
        }

        
        // void destroyIntArray(IntArray *);
        // Este metodo representa la funcion destroyIntArray
        public void destroyIntArray() {
            for (int i = 0; i < arreglo.length; i++) {
                System.out.println(arreglo[i]); // Aqui imprimimos el dato para saber que era 
                arreglo[i] = null;  // Borramos el dato. El garbage collector se encargara de hacer el mantenimiento de la memoria
            }
        }
    }
    
    // void printArray(IntArray *);
    // Este metodo representa la funcion printArray
    public void printArray() {
        for (int i = 0; i < Array.length; i++) {
            System.out.print(Array[i] + " ");
        }
    }

    public static void main(String[] args) {
        // Este seria el main equivalente en C. Lo mismo en Java como en C
        Array miArray = new Array(10);
        miArray.initIntArray();
        miArray.printArray();
        miArray.destroyIntArray();
    }
}
