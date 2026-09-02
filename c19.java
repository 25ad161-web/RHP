import java.io.*;
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int a[] = new int[N + 1];
        
        for (int i = 1; i <= N; i++) {
            a[i] = sc.nextInt();
        }
        
        long samecnt = 0, exchcnt = 0;
        
        for (int i = 1; i <= N; i++) {
            if (i == a[i]) {
                samecnt++;
            } else if (i == a[a[i]]) {
                exchcnt++;
            }
        }
        
        System.out.println(exchcnt / 2 + (samecnt * (samecnt - 1)) / 2);
    }
}