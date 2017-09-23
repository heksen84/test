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
	void CreateFont(const String &filename, const String &name);
	void DrawText(const String &fontName, float x, float y, float scale, const String &text, glm::vec3 color );
	std::map<String, Font> fonts;
};

#endif /* GUI_H_ */
