#ifndef ___WINDOW_HPP
#define ___WINDOW_HPP

#include <iostream>
#include <glew/include/GL/glew.h>
#include <glfw/include/GLFW/glfw3.h>
#include "glm/glm.hpp"


class Window
{
public:

	Window(int width = 640, int height = 480, const char* title = "Hello!");	//�R���X�g���N�^
	virtual ~Window();															//�f�X�g���N�^

	explicit operator bool();	//bool ���Z�q
	void SwapBuffers()const;	//�_�u���o�b�t�@�����O

	
	const int getKeyInput(int input);	//�L�[����
	


	//�C�x���g����
	static void Resize(GLFWwindow* const win, int width, int height);						//�T�C�Y�ύX

	const glm::vec2 getSize() const;		//�T�C�Y���擾
	
private:

	GLFWwindow *const window;	//�E�C���h�E�R���e�L�X�g

	
	glm::vec2 size;				//�E�C���h�T�C�Y
	char keyBoard[256];			//�L�[����
};

#endif

