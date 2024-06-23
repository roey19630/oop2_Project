//need to do:
// add in the constractur of every onject a init to base constarctr



#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "TextureHandler.h"
//#include "FactoryObject.h"


class BaseObject {
public:
	void setObjTexture(Object_ID name);


	BaseObject(sf::Vector2f& position) ;
	//void setObjTexture(Object_ID);
	sf::Vector2f getSpriteLocation()const;
	void move(float offsetX, float offsetY);
	void draw(sf::RenderWindow& window) const;
	void setScale(float scaleX, float scaleY);
	const sf::Sprite& getSprite() const;
	//c-tor d-tor
	BaseObject() {};
	~BaseObject() {};

protected:
	
	sf::Sprite m_objectSprite;
};