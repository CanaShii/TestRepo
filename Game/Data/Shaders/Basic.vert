attribute vec2 a_Position;

uniform vec2 u_Scale;
uniform vec2 u_Offset;
uniform vec2 u_Resolution;
uniform float u_Angle;
uniform float u_AspectRatio;

void main()
{
	vec2 pos = a_Position;

	// Scale.
	pos *= u_Scale;
	
	// Rotate.
	float newX = cos(u_Angle)*pos.x + -sin(u_Angle)*pos.y;
	float newY = sin(u_Angle)*pos.x + cos(u_Angle)*pos.y;
	pos = vec2(newX, newY);
	
	// Translate.
	pos += u_Offset;

	// Correct for aspect ratio.
	pos *= vec4( u_AspectRatio, 1, 1, 1 );

	gl_Position = vec4( pos, 0, 1 );
	
}
