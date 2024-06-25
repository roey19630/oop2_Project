#include "Board.h"
//----------------------------------------
Board::Board()
	:m_levelNum(1)
{
	/*m_colorsCodes[sf::Color(34, 177, 76)] = COLOR_OF_OBJECT::GREEN;
	m_colorsCodes[sf::Color(181, 230, 29)] = COLOR_OF_OBJECT::LIGHT_GREEN;
	m_colorsCodes[sf::Color(163, 73, 164)] = COLOR_OF_OBJECT::PURPLE;
	m_colorsCodes[sf::Color(185, 122, 87)] = COLOR_OF_OBJECT::BROWN;
	m_colorsCodes[sf::Color(63, 72, 204)] = COLOR_OF_OBJECT::BLUE;*/

	readLevel();
}
//----------------------------------------
Board::~Board()
{
}

//----------------------------------------

void Board::readLevel()
{
	std::string fileName = updateNameLevel(m_levelNum);

	readMap(fileName);
	m_levelNum++;
}
//----------------------------------------
std::string Board::updateNameLevel(int number)
{
	return "level" + std::to_string(number) + ".png";
}

//----------------------------------------
void Board::readMap(std::string fileName)
{
	auto image = sf::Image();
	float location_y = 700.f;
	float location_x = 0.f;
	sf::Color pixelColor;
	image.loadFromFile(fileName);
	for (int x = 0; x<int(image.getSize().x); x++)
	{
		location_y = 700.f;
		for (int y = int(image.getSize().y) - 1; y >= 0; y--)
		{
	
			pixelColor = image.getPixel(x, y);

			if (pixelColor == sf::Color(163, 73, 164))   //purple color
			{
				sf::Vector2f position(location_x,location_y);
				auto player = FactoryObject::createMoving(PLAYER_OBJ, position);
				m_movingObjects.push_back(std::move(player));
			}
			if (pixelColor == sf::Color(34, 177, 76))      //green color
			{
				sf::Vector2f position(location_x, location_y);
				auto tree = FactoryObject::createStatic(TREES_OBJ, position);
			}
			location_y -= 28.f;
		}
		location_x += 40.f;
	}
}





//
////----------------------------------------
//void Board::readMap(std::string fileName)
//{
//	auto image = sf::Image();
//	float location_y = 700.f;
//	float location_x = 0.f;
//	sf::Color pixelColor;
//	image.loadFromFile(fileName);
//
//	sf::Vector2f position;
//
//	for (int x = 0; x<int(image.getSize().x); x++)
//	{
//		location_y = 700.f;
//		for (int y = int(image.getSize().y) - 1; y >= 0; y--)
//		{
//
//			
//			pixelColor = image.getPixel(x, y);
//			try
//			{
//				auto currentColor = m_colorsCodes.at(pixelColor);
//			
//				switch (currentColor)
//				{
//				case COLOR_OF_OBJECT::GREEN:
//					break;
//				case COLOR_OF_OBJECT::LIGHT_GREEN:
//					break;
//				case COLOR_OF_OBJECT::PURPLE:
//				{
//					//position.x = location_x;
//					//position.y = location_y;
//					//auto player = FactoryObject::create(PLAYER_OBJ, position);
//					////m_movingObjects.push_back(std::move(player));
//					break;
//				}
//
//				case COLOR_OF_OBJECT::BROWN:
//					break;
//				case COLOR_OF_OBJECT::BLUE:
//					break;
//				default:
//					break;
//
//				}
//			}
//			catch (const std::out_of_range& e) {
//				// ����� ����� ����� �� ���� ������
//			}
//
//			/*if (pixelColor == sf::Color(34, 177, 76))      //green color
//			{
//				sf::Vector2f position(location_x, location_y);
//				auto tree = FactoryObject::create(TREES_OBJ, position);
//			}*/
//			location_y -= 28.f;
//		}
//		location_x += 40.f;
//	}
//}





void Board::draw(sf::RenderWindow* window)
{
	for (const auto& currentObject : m_movingObjects)
	{
		currentObject->draw(window);
	}
	for (const auto& currentObject : m_staticObjects)
	{
		currentObject->draw(window);
	}
}
