In this tutorial, I cover what color spaces are, how to make color space transforms, and implementation of a DaVinci Intermediate and ACES IDTs so you can use color management with cameras that aren't supported yet by Resolve.

Relevant Links:
Fuji F-Log2 and DaVinci Wide Gamut/DaVinci Intermediate data sheets are available in the below Github repo, but you can find the F-Log2 data sheet via Google and the Blackmagic one is available on their website in the Support section.

Useful formulas for XYZ and RGB matrix calculations: http://www.brucelindbloom.com/

Color Space Primaries conversion calculator: http://color.support/colorspacecalculator.html

ACES Primaries: https://en.wikipedia.org/wiki/Academy_Color_Encoding_System

Check out the notes and completed DCTLs here:
https://github.com/thatcherfreeman/dctl-tutorial

Table of Contents:
00:00 - Intro
00:45 - What is a color space?
02:37 - How do color space transforms work?
05:22 - Implementing the IDT DCTL to DWG/DI
15:07 - Validating the F-Log2 to DWG/DI IDT
19:59 - Implementing the IDT DCTL for ACES
23:30 - Installing the ACES IDT DCTL
25:46 - Conclusion and Summary
