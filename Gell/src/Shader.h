/*
 * Shader.h
 *
 *  Created on: 21 сент. 2017 г.
 *      Author: Соня
 */

#ifndef SHADER_H_
#define SHADER_H_

#include "Common.h"

class Shader {
public:
	Shader(String vertex_filename, String fragment_filename);
	void Bind();
	virtual ~Shader();
private:
	file v_file;
	file f_file;
	uint program_id;
};

#endif /* SHADER_H_ */
