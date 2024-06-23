#include "Objects.h/FreezeGiftObject.h"



bool FreezeGiftObject::m_registerit = FactoryObject::registerit(FREZE_GIFT_OBJ,
    [](const sf::Vector2f& pos) -> std::unique_ptr<BaseObject> {return std::make_unique<FreezeGiftObject>(pos); });

FreezeGiftObject::FreezeGiftObject(const sf::Vector2f& initPosition)
{
    setObjTexture(FREEZE_GIFT_OBJ);
}

FreezeGiftObject::FreezeGiftObject()
{
    setObjTexture(FREEZE_GIFT_OBJ);
}
