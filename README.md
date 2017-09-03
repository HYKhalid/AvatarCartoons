# AvatarCartoons

Create a minimal app to display cartoonish premade Avatars found in Avatars.js which are constructed from avatar components. The asset data is described in Assets.js with descriptors for { hats, beards, faces, shirts }. These assets fit pre-determined slots on the avatar: { hat, beard, face, shirt } (hair and hats are optional).

The app should consist of a simple main view that displays the selected avatar and a list of other avatars. Edit controls for customisation is not required. Visual alignment of the asset images is also not required, since they have non-standard sizes - just make sure the graphics have a consistent size.

Technical Requirements:
*) A single view done in a storyboard. Nothing fancy besides fetching and displaying the image data.
*) Avatar descriptor and related logic must be separate from the UI.
*) Data Access Layer which gets and parses the json models must be a separate component.
*) (optional bonus) Extra points if Avatar descriptors and Data Access Layer is written in C++14 instead of Obj–C or Swift.

Misc. Details:
*) Use a consistent code style of your choosing.
*) Prefer clean and simple solutions; don't worry about performance for this test task.

Give us an estimation on when you can work on this test task and how long it would take you.

Assets.js
https://s3.eu-central-1.amazonaws.com/wolf3d/Assignments/Simple+Avatar+App/Assets.js
Avatars.js
https://s3.eu-central-1.amazonaws.com/wolf3d/Assignments/Simple+Avatar+App/Avatars.js
