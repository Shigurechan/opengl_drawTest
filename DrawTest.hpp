#ifndef ___DRAWTEST_HPP
#define ___DRAWTEST_HPP


#include <iostream>
#include <glew/include/GL/glew.h>

class Shader;
class DrawTest
{
public:
	DrawTest();		//�R���X�g���N�^
	~DrawTest();	//�f�X�g���N�^

	void Update();	//�X�V
	void Draw();	//�`��

private:
	
	std::shared_ptr<Shader> shader;	//�V�F�[�_�[�N���X


	GLuint vao;	//VertexArrayObject
	GLuint vbo;	//VertexBufferObject


};

#endif
