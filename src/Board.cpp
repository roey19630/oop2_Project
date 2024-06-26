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

			if (pixelColor == sf::Color(163, 73, 164))   //purple color	player
			{
				sf::Vector2f position(location_x,location_y);
				auto player = FactoryObject::createMoving(PLAYER_OBJ, position);
				m_movingObjects.push_back(std::move(player));
			}
			else if (pixelColor == sf::Color(34, 177, 76))      //green color trees
			{
				sf::Vector2f position(location_x, location_y);
				auto tree = FactoryObject::createStatic(TREES_OBJ, position);
				m_staticObjects.push_back(std::move(tree));
			}
			else if (pixelColor == sf::Color(185,122, 87))      //brown color for wall
			{
				sf::Vector2f position(location_x, location_y);
				auto wall = FactoryObject::createStatic(WALL_OBJ, position);
				m_staticObjects.push_back(std::move(wall));
			}
			else if (pixelColor == sf::Color(0, 162,232))      //blue color for portal
			{
				sf::Vector2f position(location_x, location_y);
				auto portal = FactoryObject::createStatic(PORTAL_OBJ, position);
				m_staticObjects.push_back(std::move(portal));
			}
			else if (pixelColor == sf::Color(181, 230, 29))      //light green color for bush
			{
				sf::Vector2f position(location_x, location_y);
				auto bush = FactoryObject::createStatic(BUSH_OBJ, position);
				m_staticObjects.push_back(std::move(bush));
			}
			else if (pixelColor == sf::Color(237, 28, 36))      //red color for life gift
			{
				sf::Vector2f position(location_x, location_y);
				auto lifeGift = FactoryObject::createStatic(LIFE_GIFT_OBJ, position);
				m_staticObjects.push_back(std::move(lifeGift));
			}
			else if (pixelColor == sf::Color(153, 217, 234))      //light blue color for freeze gift
			{
				sf::Vector2f position(location_x, location_y);
				auto freezeGift = FactoryObject::createStatic(FREEZE_GIFT_OBJ, position);
				m_staticObjects.push_back(std::move(freezeGift));
			}
			else if (pixelColor == sf::Color(127, 127, 127))      //dark grey color for weapon gift
			{
				sf::Vector2f position(location_x, location_y);
				auto weaponGift = FactoryObject::createStatic(WEAPON_GIFT_OBJ, position);
				m_staticObjects.push_back(std::move(weaponGift));
			}
			else if (pixelColor == sf::Color(255, 242, 0))      //dark yellow color for small fast enemy
			{
				sf::Vector2f position(location_x, location_y);
				auto smallFastEnemy = FactoryObject::createMoving(ENEMY_1_OBJ, position);
				m_movingObjects.push_back(std::move(smallFastEnemy));
			}
			else if (pixelColor == sf::Color(255, 127, 39))      //dark orange color for big slow enemy 
			{
				sf::Vector2f position(location_x, location_y);
				auto bigSlowEnemy= FactoryObject::createMoving(ENEMY_2_OBJ, position);
				m_movingObjects.push_back(std::move(bigSlowEnemy));
			}
			else if (pixelColor == sf::Color(0, 0, 0))      //black color for poison
			{
				sf::Vector2f position(location_x, location_y);
				auto poison = FactoryObject::createStatic(POISON_OBJ, position);
				m_staticObjects.push_back(std::move(poison));
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



void Board::update(float deltatime, sf::RenderWindow* window)
{
	for (auto &currentObj : m_movingObjects)
	{
		currentObj->update(deltatime, window);
	}
}

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
