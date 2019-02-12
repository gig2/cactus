# cactus
[![FOSSA Status](https://app.fossa.io/api/projects/git%2Bgithub.com%2Fgig2%2Fcactus.svg?type=shield)](https://app.fossa.io/projects/git%2Bgithub.com%2Fgig2%2Fcactus?ref=badge_shield)

project for GIG 

For OpenMesh dependency we will use
OpenMesh from gig2 organisation with the branch add-freebsd-support
Which include the creation of openmesh.pc and install

When using cmake, OpenMESH dependency will have a fallback
as a submodule that will be get if git is present on the system.
In case of building openmesh during this project, disabling BUILD APP is recommended

If glm cannot be found, it will be get with git, in this case it is advised to disabling
GLM TEST ENABLE (replace space with underscore)


## License
[![FOSSA Status](https://app.fossa.io/api/projects/git%2Bgithub.com%2Fgig2%2Fcactus.svg?type=large)](https://app.fossa.io/projects/git%2Bgithub.com%2Fgig2%2Fcactus?ref=badge_large)