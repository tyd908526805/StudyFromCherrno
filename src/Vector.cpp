#include <iostream>
#include <string>
#include <vector>

struct Vertex
{
    float x, y, z;

    Vertex(float x, float y, float z)
        : x(x), y(y), z(z)
    {
    }

    Vertex(const Vertex& vertex)
        : x(vertex.x), y(vertex.y), z(vertex.z)
    {
        std::cout <<  "Copied!" << std::endl;
    }
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
    stream << vertex.x << "," << vertex.y <<  "," << vertex.z;
    return stream;
}

void Function(const std::vector<Vertex>& vertices)
{
}

int main()
{
    // Vertex* vertices = new Vertex[500000];
    std::vector<Vertex> vertices;
    vertices.reserve(3);
    // 使用以下参数构建了Vertex对象
    vertices.emplace_back(1, 2, 3);
    // vertices.push_back({1, 2, 3});
    // vertices.push_back({4, 5, 6});
    // vertices.push_back(Vertex(4, 5, 6));
    Function(vertices);
    for (int i = 0; i < vertices.size(); i++)
    {
        std::cout << vertices[i] << std::endl;
    }

    vertices.erase(vertices.begin() + 1);

    for (Vertex& v : vertices)
    {
        std::cout << v << std::endl;
    }

    vertices.clear();
}
