/*
 * Gui.h
 *
 *  Created on: 06 сент. 2017 г.
 *      Author: Соня
 */

#ifndef GUI_H_
#define GUI_H_

#include "Common.h"
#include "Font.h"

class Gui {
public:
	Gui();
	virtual ~Gui();
	void DrawText(const Font &font, float x, float y, const String &text );
};

#endif /* GUI_H_ */
