/*
 * AutoMacro : note.cpp
 *
 *  Created on: 17.01.2011
 *  Author: vl
 */
#include "note.h"

void ShowNoteL(const TDesC& aNote)
	{
	__LOGSTR("ShowNote");
	__LOGSTR1("ShowGlobalNote: %S",&aNote);

	CAknGlobalNote* note = CAknGlobalNote::NewLC();
	TInt NoteId;
	NoteId = note->ShowNoteL(EAknGlobalInformationNote,aNote);
	User::After(5000000);
	note->CancelNoteL(NoteId);
	__CPOPD(note);
	}
