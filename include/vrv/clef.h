/////////////////////////////////////////////////////////////////////////////
// Name:        clef.h
// Author:      Laurent Pugin
// Created:     2011
// Copyright (c) Authors and others. All rights reserved.
/////////////////////////////////////////////////////////////////////////////

#ifndef __VRV_CLEF_H__
#define __VRV_CLEF_H__

#include "atts_shared.h"
#include "layerelement.h"

namespace vrv {

class ScoreDefInterface;

//----------------------------------------------------------------------------
// Clef
//----------------------------------------------------------------------------

/**
 * This class models the MEI <clef> element.
 */
class Clef : public LayerElement,
             public AttClefShape,
             public AttColor,
             public AttLineLoc,
             public AttOctaveDisplacement {
public:
    /**
     * @name Constructors, destructors, and other standard methods
     * Reset method resets all attribute classes.
     */
    ///@{
    Clef();
    virtual ~Clef();
    virtual void Reset();
    virtual Object *Clone() const { return new Clef(*this); }
    virtual std::string GetClassName() const { return "Clef"; }
    virtual ClassId GetClassId() const { return CLEF; }
    ///@}

    /** Override the method since alignment is required */
    virtual bool HasToBeAligned() const { return true; }
                 
    /**
     * @name Setter and getter of the scoreDefElement flag
     */
    ///@{
    bool IsScoreDefElement() const { return m_isScoreDefElement; }
    void IsScoreDefElement(bool isScoreDefElement) { m_isScoreDefElement = isScoreDefElement; }
    ///@}

    /**
     * Return the offset of the clef
     */
    int GetClefLocOffset() const;

    /**
     * Return a clef id based on the various parameters
     */
    static int ClefId(data_CLEFSHAPE shape, char line, data_OCTAVE_DIS octaveDis, data_STAFFREL_basic place);

private:
    /** Flag for scoreDef or staffDef children */
    bool m_isScoreDefElement;
                 
public:
    //
private:
};

} // namespace vrv

#endif
