import matplotlib.pyplot as plt

# Dữ liệu chiều cao của cây AVL và RB
avl_height = [23, 23, 23, 23, 23, 23, 23, 23, 23, 23]
rb_height = [24, 21, 18, 24, 23, 22, 23, 23, 22, 34]

# Vẽ biểu đồ
plt.plot(avl_height, label='AVL')
plt.plot(rb_height, label='RB')

# Đặt tên cho trục x và trục y
plt.xlabel('Data')
plt.ylabel('Height')

# Đặt tiêu đề cho biểu đồ
plt.title('Comparison of Heights between AVL and RB Trees')

# Hiển thị chú thích
plt.legend()

# Hiển thị biểu đồ
plt.show()
