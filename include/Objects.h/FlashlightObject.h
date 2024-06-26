#include <SFML/Graphics.hpp>
#include <cmath>

class FlashlightObject {
public:
    FlashlightObject();

    void update(const sf::Vector2f& position, const sf::Vector2f& direction);
    sf::ConvexShape getShape();
    void draw(sf::RenderWindow* window) const;

private:
    sf::ConvexShape m_flashlightCone;
};