#ifndef ___OBJECT_H
#define ___OBJECT_H

#include <iostream>
#include <glew/include/GL/glew.h>

//�}�`�I�u�W�F�N�g
class Object
{
public:

	//���_
	struct Vertex
	{
		GLfloat position[2];	//���W
	};



	Object(GLint size,GLsizei vertexcount,const Vertex *vertex);
	virtual ~Object();
	void bind()const;
	




private:
	GLuint vao;	//���_�z��I�u�W�F�N�g
	GLuint vbo;	//���_�o�b�t�@�I�u�W�F�N�g
	Object(const Object& o);	//�R�s�[�֎~
	Object& operator = (const Object& o);	//����֎~


};



#endif
