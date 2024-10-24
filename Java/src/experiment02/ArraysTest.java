package experiment02;

import java.util.Arrays;

//Java中的Arrays中方法使用
public class ArraysTest {
    public static void main(String[] args) {
        int[] arr = {5, 2, 3, 4, 1};
        System.out.println("原数组内容:" + Arrays.toString(arr));
        Arrays.sort(arr);
        System.out.println("排序后数组内容:" + Arrays.toString(arr));
        Arrays.fill(arr, 0);
        System.out.println("填充后数组内容:" + Arrays.toString(arr));
    }
}
