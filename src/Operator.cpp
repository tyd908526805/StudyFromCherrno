#include <iostream>
#include <string>

struct Vector2
{
    float x, y;
    Vector2(float x, float y)
        : x(x), y(y)
    {
    }

    Vector2 Add(const Vector2& other) const
    {
        return Vector2(x + other.x, y + other.y);
    }
    Vector2 Add2(const Vector2& other) const
    {
        return operator+(other);
    }
    Vector2 Add3(const Vector2& other) const
    {
        return *this + other;
    }

    Vector2 operator+(const Vector2& other) const
    {
        return Add(other);
    }

    Vector2 Multiply(const Vector2& other) const
    {
        return Vector2(x * other.x, y * other.y);
    }

    Vector2 operator*(const Vector2& other) const
    {
        return Multiply(other);
    }

    // 浮点数不能直接判断相等 需要相减取模
    bool operator==(const Vector2& other) const
    {
        return x == other.x && y == other.y;
    }
    bool operator!=(const Vector2& other) const
    {
        //return operator==(other);
        return !(*this == other);
    }

};

std::ostream& operator<<(std::ostream& stream, const Vector2& other)
{
    stream << other.x << ", " << other.y;
    return stream;
}

#if 0
int main()
{
    Vector2 position(4.0f, 4.0f);
    Vector2 speed(0.5f, 1.5f);
    Vector2 powerup(2.0f, 2.0f);
    Vector2 power(2.0f, 2.0f);

    Vector2 result1 = position.Add(speed.Multiply(powerup));
    Vector2 result2 = position + speed * powerup;
    Vector2 result3 = speed * powerup + position;
    //std::cout << "result2: " << result2.x << " "  << result2.y << std::endl;
    //std::cout << "result3: " << result3.x << " "  << result3.y << std::endl;
    
    std::cout << result2 << std::endl;
    int re = speed == powerup ? 1 : 2;
    std::cout << re << std::endl;
    re = powerup == powerup ? 1 : 2;
    std::cout << re << std::endl;
}
#endif
