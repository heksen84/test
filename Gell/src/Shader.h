/*
 * Shader.h
 *
 *  Created on: 21 сент. 2017 г.
 *      Author: Соня
 */

#ifndef SHADER_H_
#define SHADER_H_

enum ShaderType{
	VERTEX_SHADER,
	FRAGMENT_SHADER
};

class Shader {
public:
	Shader(ShaderType type);
	void Bind();
	virtual ~Shader();
};

#endif /* SHADER_H_ */
