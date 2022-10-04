attribute vec2 a_Position;

uniform vec2 u_Scale;
uniform float u_Offset;
uniform vec2 u_Resolution;

void main()
{
	vec2 scale = vec2(u_Scale);
	float angle = 0.0 / 180.0 * 3.1415;
	vec2 offset = vec2(u_Offset,0);
	
	vec2 pos = a_Position;

	// Scale.
	pos *= scale;
	
	// Rotate.
	float newX = cos(angle)*pos.x + -sin(angle)*pos.y;
	float newY = sin(angle)*pos.x + cos(angle)*pos.y;
	pos = vec2(newX, newY);
	
	// Translate.
	pos += offset;

	//gl_Position.xy *= pos;
	
	gl_Position = vec4( pos, 0, 1 );
	gl_Position.xy *= vec2(u_Resolution.y/u_Resolution.x, 1); 
	
}
