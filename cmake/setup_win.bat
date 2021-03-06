@echo off

if not exist "%UserProfile%\.OpenRaider" (
	echo Setting up for %UserName%...
	mkdir "%UserProfile%\.OpenRaider"
	mkdir %UserProfile%\.OpenRaider\paks
	mkdir %UserProfile%\.OpenRaider\music
	mkdir %UserProfile%\.OpenRaider\data
	mkdir %UserProfile%\.OpenRaider\sshots
	copy data\OpenRaider.ini %UserProfile%\.OpenRaider
	copy data\*.tga %UserProfile%\.OpenRaider\data
	echo Done!
) else (
	echo Already done
)
