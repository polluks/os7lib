/**
 * @brief Complex Object demo (Mode 2)
 * @author Thomas Cherryhomes
 * @email thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see COPYING for details
 */

#ifndef SOUND_DATA_AREA_H
#define SOUND_DATA_AREA_H

unsigned char output0[10];

const unsigned char sound0[] =
  {
    // measure 1, 16th notes, notes are in octave above middle C, at full volume.
    0x40, 0x4b, 0x02, 0x08, // D
    0x40, 0x93, 0x02, 0x08, // E
    0x40, 0xba, 0x02, 0x08, // F
    0x40, 0x10, 0x03, 0x08, // G
    0x40, 0x70, 0x03, 0x08, // A
    0x40, 0xa4, 0x03, 0x08, // Ab

    // measure 2, 16 notes
    0x40, 0x2a, 0x02, 0x08, // Db
    0x40, 0xa4, 0x03, 0x08, // Ab
    0x40, 0x70, 0x03, 0x08, // A
    0x40, 0x10, 0x03, 0x08, // G
    0x40, 0xba, 0x02, 0x08, // F
    0x40, 0x93, 0x02, 0x08, // E
  };

const void *soundTable[] = {&sound0,&output0};

#endif /* SOUND_DATA_AREA_H */
