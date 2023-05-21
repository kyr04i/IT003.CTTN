# AVL - Red_Black Tree

> Project requirements :
* Generate 10 random tuples, each with about 10^6 values
* Install AVL tree and Red-Black tree
* Run the tree creation test by adding the generated tuple numbers one by one
* Record tree height, draw a graph comparing tree heights and logN values, 1.45logN
* Write an experimental report

> Author: w1n_gl0ry

# Report IT003 - Tree DataStructures:

> Họ và tên: Nguyễn Viết Duy

> MSSV: 22520336

>> $ AVL Tree

> Là loại cây tìm kiếm nhị phân tự cân bằng, được gọi là AVL Tree, có những đặc tính sau:

* Tại mỗi nút của cây, độ chênh lệch giữa độ cao của cây con trái và cây con phải không vượt quá một.

* Với một cây AVL có N nút, chiều cao của cây là log(N).

>Một nút trong cây AVL có chỉ số cân bằng, được tính bằng hiệu của chiều cao của cây con phải và cây con trái của nút đó. Trong một cây cân bằng, chỉ số cân bằng chỉ có thể có một trong ba giá trị là -1, 1 hoặc 0.

>Ngoài các thao tác thông thường của cây tìm kiếm nhị phân, cây AVL có thêm các thao tác đặc trưng sau:

* Thêm một phần tử vào cây AVL.
* Xóa một phần tử từ cây AVL.
* Cân bằng lại cây sau khi cây bị mất cân bằng.

>Mỗi khi chèn hoặc xóa một nút, nếu cây mất cân bằng, có thể xảy ra một trong bốn trường hợp sau:

* Trường hợp Left Left: Điều này xảy ra khi nút được chèn vào cây con trái của cây con trái của nút gốc.
* Trường hợp Left Right: Điều này xảy ra khi nút được chèn vào cây con phải của cây con trái của nút gốc.
* Trường hợp Right Right: Điều này xảy ra khi nút được chèn vào cây con phải của cây con phải của nút gốc.
* Trường hợp Right Left: Điều này xảy ra khi nút được chèn vào cây con trái của cây con phải của nút gốc.

> Để hiện thực cây AVL, có thể sử dụng các phương pháp và thuật toán được cung cấp trong tệp  [AVL.cpp](https://github.com/w1n-gl0ry/Data_Structures_and_Algotithms/blob/main/Project2/AVL.cpp)

>> $ Red Black Tree

> Cây đỏ đen là một cấu trúc dữ liệu được phát triển từ cây AVL và có những tính chất đặc trưng sau:

* Mỗi nút trong cây đỏ đen có màu đỏ hoặc đen.

* Nút gốc (root) luôn phải có màu đen.

* Không có hai nút đỏ liền kề, tức là một nút đỏ không thể có cha hoặc con đỏ.

* Mọi đường dẫn từ một nút tới các nút NULL (các nút lá hoặc nút không có con) phải chứa cùng số lượng nút đen.

* Tất cả các nút lá (NULL) được coi là nút đen.
Chiều cao của cây đỏ đen với N nút luôn nhỏ hơn 2*log(N+1).

* Các thao tác trên cây đỏ đen tương tự như cây nhị phân tìm kiếm thông thường, nhưng cần đảm bảo tuân thủ các tính chất màu sắc.

>> Để hiện thực cây RB, có thể sử dụng các phương pháp và thuật toán được cung cấp trong tệp  [RB.cpp](https://github.com/w1n-gl0ry/Data_Structures_and_Algotithms/blob/main/Project2/RB.cpp)


>> $ Tổng kết

```
So sánh cây AVL và cây đỏ đen: cây AVL cân bằng hơn cây đỏ đen, nhưng có thể tạo ra nhiều chuyển động quay hơn trong quá trình chèn và xóa. Vì vậy, nếu cần chèn và xóa thường xuyên, thì cây đỏ đen nên được ưu tiên hơn. Và ngược lại nếu hoạt động tìm kiếm diễn ra thường xuyên hơn, thì cây AVL sẽ được ưu tiên hơn cây đỏ đen.
```

` Bảng so sánh chiều cao giữa 2 cây:`
| Data| AVL    | RB   |
| :---:   | :---: | :---: |
| 1 | 23   |  24 |
| 2 |   23 |  21 |
| 3 |    23|  18 |
| 4 |   23 |  24 |
| 5 |   23 |  23 |
| 6 |   23 |  22 |
| 7 |   23 |  23 |
| 8 |   23 |  23 |
| 9 |    23|  22 |
| 10 |   23| 34 |

`Biều đồ thực nghiệm: `
![haha.png](https://github.com/w1n-gl0ry/Data_Structures_and_Algotithms/blob/main/Project2/AVL%26RB.png)

