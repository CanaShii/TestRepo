#include "CoreHeaders.h"
#include "Mesh.h"
#include "Utility/ShaderProgram.h"
#include "Math/Vector.h"
#include "Mesh/Texture.h"
#include "BaseComponent.h"
#include "RenderableComponent.h"
#include "TransformComponent.h"

namespace fw {

Mesh::Mesh(std::vector<VertexFormat>& verts, int primType)
{
    glGenBuffers( 1, &m_VBO );
    glBindBuffer( GL_ARRAY_BUFFER, m_VBO );
    glBufferData( GL_ARRAY_BUFFER, verts.size() * sizeof(fw::VertexFormat), &verts[0], GL_STATIC_DRAW);

    m_NumVerts = (int)verts.size();
    m_PrimitiveType = primType;
}

Mesh::~Mesh()
{
    glDeleteBuffers( 1, &m_VBO );
}

void Mesh::Draw(RenderableComponent* pRComponent, TransformComponent* pTComponent, float aspectRatio)
{
    // Activate our basic shader.
    glUseProgram(pRComponent->m_pShader->GetProgram());//pShader->GetProgram();

    // Program our uniforms.
    //SetUniform( pShader, "u_Scale", scale );
    //SetUniform( pShader, "u_Angle", angle);
    //SetUniform( pShader, "u_Offset", pos);
    //SetUniform( pShader, "u_Color", 255, 255, 255, 255 );
    //SetUniform( pShader, "u_CameraPosition", vec2(0,0) );
    //SetUniform( pShader, "u_ProjectionScale", vec2(1,1) * aspectRatio );
    //SetUniform( pShader, "u_UVScale", vec2(1,1) );
    //SetUniform( pShader, "u_UVOffset", vec2(0,0) );

    GLint u_Scale = glGetUniformLocation(pRComponent->m_pShader->GetProgram(), "u_Scale");
    glUniform2f( u_Scale, pTComponent->m_Scale.x, pTComponent->m_Scale.y);

    GLint u_Angle = glGetUniformLocation(pRComponent->m_pShader->GetProgram(), "u_Angle");
    glUniform1f( u_Angle, pTComponent->m_Angle);

    GLint u_Offset = glGetUniformLocation(pRComponent->m_pShader->GetProgram(), "u_Offset");
    glUniform2f( u_Offset, pTComponent->m_Pos.x, pTComponent->m_Pos.y );

    GLint u_Color = glGetUniformLocation(pRComponent->m_pShader->GetProgram(), "u_Color");
    glUniform4f( u_Color, 255, 255, 255, 255 );

    GLint u_UVScale = glGetUniformLocation(pRComponent->m_pShader->GetProgram(), "u_UVScale");
    glUniform2f( u_UVScale, 1, 1 );

    GLint u_UVOffset = glGetUniformLocation(pRComponent->m_pShader->GetProgram(), "u_UVOffset");
    glUniform2f( u_UVOffset, 0, 0 );

    GLint u_AspectRatio = glGetUniformLocation(pRComponent->m_pShader->GetProgram(), "u_AspectRatio");
    glUniform1f( u_AspectRatio, aspectRatio );

    int textureUnitNumber = 0;
    glActiveTexture(GL_TEXTURE0 + textureUnitNumber);
    glBindTexture(GL_TEXTURE_2D, pRComponent->m_pTexture->GetTextureID());
    GLint u_ColorTexture = glGetUniformLocation(pRComponent->m_pShader->GetProgram(), "u_ColorTexture");
    glUniform1i(u_ColorTexture, textureUnitNumber);

    // Draw our mesh.
    glBindBuffer( GL_ARRAY_BUFFER, m_VBO );

    GLint a_Position = glGetAttribLocation(pRComponent->m_pShader->GetProgram(), "a_Position");
    glEnableVertexAttribArray( a_Position );
    glVertexAttribPointer( a_Position, 2, GL_FLOAT, false, sizeof(VertexFormat), (void*)offsetof(VertexFormat, pos));

    GLint a_Color = glGetAttribLocation(pRComponent->m_pShader->GetProgram(), "a_Color");
    glEnableVertexAttribArray( a_Color );
    glVertexAttribPointer( a_Color, 4, GL_UNSIGNED_BYTE, true, sizeof(VertexFormat), (void*)offsetof(VertexFormat, r) );

    GLint a_UV = glGetAttribLocation(pRComponent->m_pShader->GetProgram(), "a_UV");
    glEnableVertexAttribArray( a_UV );
    glVertexAttribPointer( a_UV, 2, GL_FLOAT, false, sizeof(VertexFormat), (void*)offsetof(VertexFormat,uv) );

    glDrawArrays( m_PrimitiveType, 0, m_NumVerts );
}

}
