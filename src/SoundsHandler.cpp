
#include "SoundsHandler.h"

SoundsHandler::~SoundsHandler() {}



// loadds the sounds into the buffer array
SoundsHandler::SoundsHandler()
{
//    for (int i = 0; i < SOUND_NUM; i++)
//    {
//       // m_buffers[i].loadFromFile(m_soundNames[i]);
//    }
//
//    // matches each sound with it's own buffer
//    for (int i = 0; i < SOUND_NUM; i++)
//    {
//        //m_sounds[i].setBuffer(m_buffers[i]);
//    }
}
 
 
SoundsHandler& SoundsHandler::getInstance()
{
    static SoundsHandler instance;
    return instance;
}

void SoundsHandler::playSound(Sound_Id id)
{
    //m_sounds[id].play();
}