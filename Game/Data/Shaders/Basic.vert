attribute vec2 a_Position;

uniform vec2 u_Scale;
uniform vec2 u_Offset;
uniform vec2 u_Resolution;
uniform float u_Rotation;
attribute vec4 a_Color;
varying vec4 v_Color;

void main()
{
	vec2 scale = vec2(u_Scale);
	float angle = u_Rotation;
	vec2 offset = u_Offset;
	
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
	
	gl_Position = vec4( pos/5, 0, 1 );
	gl_Position.xy *= vec2(u_Resolution.y/u_Resolution.x, 1); 
	v_Color = a_Color;
	
}
