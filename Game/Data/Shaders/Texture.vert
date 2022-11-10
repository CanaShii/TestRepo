attribute vec2 a_Position;
attribute vec2 a_UV;

uniform vec2 u_Scale;
uniform float u_Angle;
uniform vec2 u_Offset;
uniform vec2 u_uvScale;
uniform vec2 u_uvOffset;
uniform vec2 u_CameraPosition; 
uniform vec2 u_ProjectionScale;

varying vec2 v_UV;

vec2 TransformToWorldSpace(vec2 pos);

void main()
{

	vec2 ObjectPos = a_Position;
	vec2 WorldPos = TransformToWorldSpace(ObjectPos);
	vec2 ViewPos = WorldPos - u_CameraPosition;
	vec2 ClipPos = ViewPos * u_ProjectionScale;


	gl_Position = vec4( ClipPos, 0, 1 );

	v_UV = a_UV * u_uvScale + u_uvOffset;
}

vec2 TransformToWorldSpace(vec2 pos)
{

	// Scale.
	pos *= u_Scale;
	
	// Rotate.
	float newX = cos(u_Angle)*pos.x + -sin(u_Angle)*pos.y;
	float newY = sin(u_Angle)*pos.x + cos(u_Angle)*pos.y;
	pos = vec2(newX, newY);
	
	// Translate.
	pos += u_Offset;

	return pos;
}