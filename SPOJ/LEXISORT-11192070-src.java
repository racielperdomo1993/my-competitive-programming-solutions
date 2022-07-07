

import java.util.Arrays;
import java.util.Scanner;

public class Main {
    
    private static void Merge(Comparable[] a1, Comparable[] a2, Comparable[] a, int n)
    {
        int i,j,k;
        i=j=k=0;
        while(i<n/2 && j < n-n/2)
        {
            if(a1[i].compareTo(a2[j]) < 0)
            {
                a[k] = a1[i];
                i++;k++;
            }else{
                a[k] = a2[j];
                j++;k++;
            }
        }
        while(i < n/2)
        {
            a[k] = a1[i];
            i++;
            k++;
        }
        while(j<n-n/2)
        {
            a[k] = a2[j];
            j++;
            k++;
        }
    }
    public static void MergeSort(Comparable[] elementos, int n){
        //código por implementar en el Laboratorio 3
        if(n > 1)
        {
            
            
            Comparable[] a1 = new Comparable[n/2];
            Comparable[] a2 = new Comparable[n-(n/2)];
            System.arraycopy(elementos, 0, a1, 0, n/2);
            System.arraycopy(elementos, n/2, a2, 0, n - n/2);
            MergeSort(a1, n/2);
            MergeSort(a2, n-n/2);
            Merge(a1,a2,elementos, n);
        }
    }
    
    
    public static void main(String[] args) {
        //cascarón para resolver http://www.spoj.com/problems/LEXISORT/ (Easy Sorting)
        
        Scanner sc = new Scanner(System.in);
        String[] arr = new String[50005];
        int t, n;
        t = sc.nextInt();
        for(int i = 0; i < t; i++){
            n = sc.nextInt();
            for (int j = 0; j < n; j++) {
                arr[j] = sc.next();
            }
            MergeSort(arr, n);
            for (int j = 0; j < n; j++) {
                System.out.println(arr[j]);
            }
        }
    }
}
