#include "Shader.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//�R���X�g���N�^
Shader::Shader(const char* vert, const char* frag)
{
	program = loadProgram(vert,frag);
	if (program == 0)
	{
		std::cerr << "�V�F�[�_�[�v���O�����쐬�G���["<<std::endl;
		exit(1);
	}


	

	//std::cout<< program << std::endl;

}

//�V�F�[�_�[�����[�h
GLuint Shader::loadProgram(const char* vert, const char* frag)
{
	std::vector<GLchar> vsrc;
	const bool vstat = ReadShaderSource(vert, vsrc);

	std::vector<GLchar> fsrc;
	const bool fstat = ReadShaderSource(frag, fsrc);


	if (vstat && fstat)
	{
		return CreateProgram(vsrc.data(), fsrc.data());
	}
	else {
		return 0;
	}
}



//�V�F�[�_�[�t�@�C����ǂݍ���
bool Shader::ReadShaderSource(const char* name, std::vector<GLchar>& buffer)
{
	if (name == NULL)
	{
		return false;
	}
	

	std::ifstream file(name, std::ios::binary);
	if (file.fail())
	{
		std::cerr << "�\�[�X�t�@�C�����ǂݍ��߂܂���: " << name << std::endl;
		file.close();
		return false;
	}

	file.seekg(0L, std::ios::end);
	GLsizei length = static_cast<GLsizei>(file.tellg());
	buffer.resize(length + 1);

	file.seekg(0L, std::ios::beg);
	file.read(buffer.data(), length);
	buffer[length] = '\0';
	
	if (file.fail())
	{
		std::cerr << "�\�[�X�t�@�C����ǂݍ��߂܂���: " << name << std::endl;
		file.close();

		return false;
	}

	file.close();
	return true;
}



//�G���[���O���擾
GLboolean Shader::InfoLog(GLuint shader, const char* str)
{
	GLint status;

	//�R���p�C������
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
	if (status == GL_FALSE)
	{
		std::cerr << "�R���p�C���G���[�@" << str << std::endl;
	}
	
	//�G���[���O�̒����𓾂�
	GLsizei bufSize;
	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &bufSize);

	if (bufSize > 1)
	{
		std::vector<GLchar> infoLog(bufSize);
		GLsizei length;
		glGetShaderInfoLog(shader, bufSize, &length, &infoLog[0]);

		std::cerr<< &infoLog[0] << std::endl;
	}



	return (GLboolean)status;
}




//�v���O�����I�u�W�F�N�g�쐬
GLuint Shader::CreateProgram(const char* vsrc, const char* fsrc)
{
	const GLuint program = glCreateProgram();	//�V�F�[�_�[�v���O�������쐬

	//std::cout << program << std::endl;

	if (vsrc != NULL)
	{
		const GLuint vobj = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vobj, 1, &vsrc, NULL);
		glCompileShader(vobj);

		InfoLog(vobj, vsrc);

		glAttachShader(program, vobj);
		glDeleteShader(vobj);

	}
	else {
		std::cout << "���_�V�F�[�_�[�ǂݍ��ݎ��s" << std::endl;
	}

	if (fsrc != NULL)
	{
		const GLuint fobj = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fobj, 1, &fsrc, NULL);
		glCompileShader(fobj);

		InfoLog(fobj, fsrc);

		glAttachShader(program, fobj);
		glDeleteShader(fobj);
	}
	else {
		std::cout << "�t���O�����g�V�F�[�_�[�ǂݍ��ݎ��s" << std::endl;

	}

	glLinkProgram(program);




	return program;
}

//���_�V�F�[�_�[�ɑ����ϐ����֘A������
void Shader::setBindAttribVertex(const char* str)
{
	GLint n = glGetAttribLocation(program, str);

	//�G���[����
	if (n == -1)
	{
		std::cerr <<"setBindAttribVertex(): "<< n << std::endl;
	}
	else 
	{
		glBindAttribLocation(program, n, str);
	}
}


//�t���O�����g�V�F�[�_�[�ɑ����ϐ����֘A������
void Shader::setBindAttribFragment(const char* str)
{
	GLint n = glGetAttribLocation(program, str);

	//�G���[����
	if (n == -1)
	{
		std::cerr << "setBindAttribFragment(): " << n << std::endl;
	}
	else 
	{
		glBindFragDataLocation(program, n, str);
	}
}

//�L���ɂ���
void Shader::setEnable()
{
	glUseProgram(program);

}

//�����ɂ���
void Shader::setDisable()
{
	glUseProgram(0);

}


//�@######################################################### Uniform �ݒ�

//vec1
void Shader::setUniform1f(const char* name, const float vec)
{
	const GLuint object = glGetUniformLocation(program, name);
	glUniform1f(object,vec);
}

//vec2
void Shader::setUniform2f(const char* name, const glm::vec2 vec)
{
	const GLuint object = glGetUniformLocation(program, name);
	glUniform2f(object,vec.x,vec.y);
}

//vec3
void Shader::setUniform3f(const char* name, const glm::vec3 vec)
{
	const GLuint object = glGetUniformLocation(program, name);
	glUniform3f(object,vec.x, vec.y,vec.z);
}

//vec 4
void Shader::setUniform4f(const char* name, const glm::vec4 vec)
{	
	const GLuint object = glGetUniformLocation(program,name);
	if (object == -1)
	{
		std::cerr << "setUniform4f(): " << object << std::endl;
	}
	else {
		glUniform4f(object, vec.x, vec.y, vec.z, vec.w);
	}
}



//�f�X�g���N�^
Shader::~Shader()
{

}
