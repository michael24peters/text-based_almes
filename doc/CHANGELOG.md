# CHANGELOG
Below are the current contributions to the project, divided into versions in order of release. Branch version are organized by:

X.0.0 (major working state)
0.Y.0 (branch)
0.0.Z (features/changes/fixes)

## v0.0.1
- docs: created char_pseudo.txt
- docs: created CHANGELOG.md
- feat: character.cpp

## v0.0.2
- feat: added intro.txt
  - Rough draft of first scene

## v0.0.3
- feat: Two rough drafts of second scene in intro.txt

## v0.0.4
- style: renamed character.cpp to Character.cpp
- feat: Character class in Character.cpp
  - Constructors
  - Getters & setters (all class vars are currently private)
  - progress_algorithm declared but not defined

## v0.0.5
- fix: Character constructors now properly handle hit_points and languages
- style: changed .cpp to .cc file extension
- docs: additional comments to Character.cc

## v0.0.6
- feat: added Character.h

## v0.0.7
- feat: added NPC.cc
  - Required adding copy constructor to Character
- refactor: Character constructors reworked

## v0.0.8
- feat: added Makefile

## v0.0.9
- style: lower case on all files
- fix: Makefile now compiles without error
- feat: dummy run.cc file to test make

## v0.0.10
- feat: added print() to main.cc for slowed text output to sh
- refactor: created doc/ directory, moved relevant files

## v0.0.11
- feat: npc.h
- feat: print() method declared but undefined for Character and NPC

## v0.1.0
- branch: char branch merged into main
- docs: README.md updated

## v0.1.1
- feat: .pre-commit-config.yaml
  - https://github.com/pre-commit/pre-commit-hooks 
  - https://github.com/pocc/pre-commit-hooks