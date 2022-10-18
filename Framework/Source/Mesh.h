#pragma once
#include "GameCore.h"
#include "CoreHeaders.h"
#include <vector>






namespace fw {

   struct VertexFormat
   {
	   fw::vec2 Pos;
	   unsigned char r, g, b, a;
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
	   ~Mesh();

	   void drawMesh(ShaderProgram* shader, vec2 scale, float angle, vec2 pos);

   protected:
	
	   float m_ElapsedTime = 0.0f;

	   std::vector<VertexFormat> m_Format;
	
	   //PrimitiveTypes m_Mode;

	   int m_NumOfObjects = 0;

	   PrimitiveTypes m_Mode;

	   GLuint m_VBO = 0;

	   //fw::FWCore& m_Framework;
   };

}