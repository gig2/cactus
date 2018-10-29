# cactus
project for GIG 

For OpenMesh dependency we will use
OpenMesh from gig2 organisation with the branch add-freebsd-support
Which include the creation of openmesh.pc and install

When using cmake, OpenMESH dependency will have a fallback
as a submodule that will be get if git is present on the system.
In case of building openmesh during this project, disabling BUILD APP is recommended
