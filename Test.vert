

in vec2 position;
uniform vec4 ufragment;

out vec4 vfragment;
void main()
{
	gl_Position =  vec4(position.x,position.y,1.0,1.0);	//À•W
	vfragment = ufragment;								//ƒJƒ‰[
}