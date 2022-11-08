#pragma once
#include "GameCore.h"
#include "CoreHeaders.h"
#include <vector>
#include "Math/vec2.h"






namespace fw {

	class ShaderProgram;
	class Texture;

   struct VertexFormat
   {
	   vec2 pos;
	   unsigned char r, g, b, a;
	   vec2 uv;
   };

   enum class PrimitiveTypes
   {
       GLPOINTS,
	   GLLINES,
       GLTRIANGLE
   };


   class ShaderProgram;

   class Mesh
   {
   public:
	   Mesh(std::vector<VertexFormat>& vertex, PrimitiveTypes mode);
	   virtual ~Mesh();

	   void drawMesh(ShaderProgram* shader,fw::Texture* texture, vec2 scale, float angle, vec2 pos, float aRatio);

   protected:
	
	   float m_ElapsedTime = 0.0f;

	   std::vector<VertexFormat> m_Format;
	
	   int m_NumOfObjects = 0;

	   PrimitiveTypes m_Mode;

	   GLuint m_VBO = 0;

	   //fw::FWCore& m_Framework;
   };

}