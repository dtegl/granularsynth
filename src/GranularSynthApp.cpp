#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "AudioEngine.h"
#include "SampleLoader.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class GranularSynthApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
};

void GranularSynthApp::setup()
{

}

void GranularSynthApp::mouseDown( MouseEvent event )
{
}

void GranularSynthApp::update()
{
}

void GranularSynthApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP( GranularSynthApp, RendererGl )
