#pragma once

#include <GL/glew.h>

#include "OpenGLMeshRender/meshnode.h"
#include "OpenGLShader/shader.h"
#include "mesh.h"
#include "valence.h"

#include <QOpenGLWidget>

#ifndef GLM_FORCE_RADIANS
#define GLM_FORCE_RADIANS
#endif
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <memory>
#include <vector>

class ModelVisu : public QOpenGLWidget
{
    Q_OBJECT
public:
    explicit ModelVisu( QWidget *parent );


signals:
    void minValenceChanged( int );
    void maxValenceChanged( int );
    void medianValenceChanged( double );
    void averageValenceChanged( double );

protected:
    void initializeGL() override;

    void resizeGL( int width, int height ) override;

    void paintGL() override;




public slots:
    void addMesh( QString model );
    void setYaw( int );
    void setPitch( int );
    void setRoll( int );
    void setScale( double );
    void computeValenceRequested();

private:
    // get them from shader
    int const positionLocation_{0};
    int const colorLocation_{1};


    std::vector<std::shared_ptr<Mesh>> mesh_;
    std::vector<std::shared_ptr<MeshNode<Mesh>>> meshNode_;

    std::vector<Valence> valences_;


    S3DE::Shader simpleShader_;

    glm::mat4 objTransform_{1.f};

    glm::mat4 eulerTransform_{1.f};

    glm::mat4 scaleTransform_{1.f};

    glm::mat4 projection_;
    glm::mat4 modelview_;

    float yaw_{0.};
    float pitch_{0.};
    float roll_{0.};

    float scale_{1.};

    void updateEuler_();
    void updateValenceColor_();
};
