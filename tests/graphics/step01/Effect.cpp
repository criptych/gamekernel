#include "stdafx.h"

#include "Effect.h"

Effect::Effect( ID3DXEFFECT* effect )
: m_effect( effect )
{
	K_ASSERT( m_effect != 0 );
}

Effect::~Effect()
{
	if ( m_effect != 0 )
	{
		K_DELETE( m_effect );
	}
}

bool Effect::SetMatrix( const std::string& name, D3DXMATRIXA16* matrix )
{
	return SUCCEEDED( m_effect->SetMatrix( name.c_str(), matrix ) );
}

bool Effect::SetTexture( const std::string& name, Texture* tex )
{
	return SUCCEEDED( m_effect->SetMatrix( name.c_str(), matrix ) );
}

bool Effect::SetValue( const std::string& name, void* v, uint size )
{
	K_ASSERT( v != 0 );
	K_ASSERT( size > 0 );

	return SUCCEEDED( m_effect->SetValue( name.c_str(), v, size ) ); 
}

bool Effect::Begin( uint& passes )
{
	return SUCCEEDED( m_effect->Begin(passes, 0) );
}

bool Effect::BeginPass( uint pass )
{
	return SUCCEEDED( m_effect->BeginPass( pass ) ); 
}

bool Effect::EndPass()
{
	return SUCCEEDED( m_effect->EndPass() );
}

bool Effect::End()
{
	return SUCCEEDED( m_effect->End() );
}

void Effect::OnLost()
{
	// TODO: resource handling
}

void Effect::OnRestored()
{
	// TODO: resoruce handling
}
