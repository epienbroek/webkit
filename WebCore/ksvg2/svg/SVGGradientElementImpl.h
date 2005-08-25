/*
    Copyright (C) 2004, 2005 Nikolas Zimmermann <wildfox@kde.org>
				  2004, 2005 Rob Buis <buis@kde.org>

    This file is part of the KDE project

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
    Boston, MA 02111-1307, USA.
*/

#ifndef KSVG_SVGGradientElementImpl_H
#define KSVG_SVGGradientElementImpl_H

#include "SVGURIReferenceImpl.h"
#include "SVGStyledElementImpl.h"
#include "SVGExternalResourcesRequiredImpl.h"

#include <kcanvas/KCanvasResourceListener.h>

class KCanvas;
class KRenderingPaintServerGradient;

namespace KSVG
{
	class SVGGradientElementImpl;
	class SVGAnimatedEnumerationImpl;
	class SVGAnimatedTransformListImpl;
	class SVGGradientElementImpl : public SVGStyledElementImpl,
								   public SVGURIReferenceImpl,
								   public SVGExternalResourcesRequiredImpl,
								   public KCanvasResourceListener
	{
	public:
		SVGGradientElementImpl(KDOM::DocumentPtr *doc, KDOM::NodeImpl::Id id, KDOM::DOMStringImpl *prefix);
		virtual ~SVGGradientElementImpl();

		// 'SVGGradientElement' functions
		SVGAnimatedEnumerationImpl *gradientUnits() const;
		SVGAnimatedTransformListImpl *gradientTransform() const;
		SVGAnimatedEnumerationImpl *spreadMethod() const;

		virtual void parseAttribute(KDOM::AttributeImpl *attr);
		virtual void notifyAttributeChange() const;

	protected:
		virtual void buildGradient(KRenderingPaintServerGradient *grad, KCanvas *canvas) const = 0;

	protected:
		mutable SVGAnimatedEnumerationImpl *m_spreadMethod;
		mutable SVGAnimatedEnumerationImpl *m_gradientUnits;
		mutable SVGAnimatedTransformListImpl *m_gradientTransform;
	};
};

#endif

// vim:ts=4:noet
