#include <bits/stdc++.h> // Cần thiết nếu dùng std::list::remove

// Định nghĩa số lượng đỉnh (Giả sử N đỉnh)
const int N = 5;

// Hàm tìm Chu trình/Đường đi Euler
// u: Đỉnh bắt đầu
// adj: Danh sách kề của đồ thị (Lưu ý: adj được truyền tham chiếu để chỉnh sửa trực tiếp)
// W: Kết quả đường đi (Chu trình/Đường đi Euler)
void findEulerPath(int u, std::vector<std::list<int>>& adj, std::vector<int>& W) {

    // Line 1: Khởi tạo stack và W
    std::stack<int> s;
    // std::vector<int> W đã được khởi tạo bên ngoài và truyền vào

    // Line 2: stack <- u
    s.push(u);

    // Line 3: while stack != empty do
    while (!s.empty()) {

        // Line 4: x <- top(stack)
        int x = s.top();

        // Line 5: if ke(x) != empty then
        if (!adj[x].empty()) {

            // Line 6: y <- top(ke(x)) (Chọn đỉnh kề đầu tiên)
            // Lấy đỉnh kề đầu tiên từ list kề của x
            int y = adj[x].front();

            // Line 7: stack <- y
            s.push(y);

            // Line 8, 9: Thực hiện xóa cạnh (x,y) và (y,x)
            // Xóa y khỏi danh sách kề của x
            adj[x].remove(y);
            // Xóa x khỏi danh sách kề của y (Đảm bảo đồ thị vô hướng)
            adj[y].remove(x);

        } else {

            // Line 10: else /* x là đỉnh cô lập */

            // Line 11: x <- stack (Thực hiện pop x)
            // Đỉnh x không còn cạnh kề, đã đến lúc đưa nó vào kết quả
            s.pop();

            // Line 12: W <- x
            // Đưa đỉnh x vào cuối đường đi W
            W.push_back(x);
        }
    }
}

// Hàm Main (Ví dụ sử dụng)
int main() {
    // Sử dụng Danh sách kề (Adjacency List) với std::list để dễ dàng xóa cạnh
    // Kích thước N+1 để sử dụng chỉ mục từ 1 đến N
    std::vector<std::list<int>> adj(N + 1);
    std::vector<int> W;

    // Xây dựng đồ thị có Chu trình Euler (Ví dụ đơn giản: 1-2-3-4-1)
    // Cạnh (1, 2)
    adj[1].push_back(2);
    adj[2].push_back(1);
    // Cạnh (2, 3)
    adj[2].push_back(3);
    adj[3].push_back(2);
    // Cạnh (3, 4)
    adj[3].push_back(4);
    adj[4].push_back(3);
    // Cạnh (4, 1)
    adj[4].push_back(1);
    adj[1].push_back(4);

    // Bắt đầu tìm Chu trình Euler từ đỉnh u = 1
    int start_node = 1;
    findEulerPath(start_node, adj, W);

    // In kết quả (Đường đi Euler sẽ bị đảo ngược khi in ra từ W, cần in ngược)
    std::cout << "Chu trinh Euler (In nguoc vi stack): ";
    for (int i = W.size() - 1; i >= 0; --i) {
        std::cout << W[i] << (i == 0 ? "" : " -> ");
    }
    std::cout << std::endl;
    // Kết quả: 1 -> 4 -> 3 -> 2 -> 1 (hoặc một chu trình tương đương)

    return 0;
}
