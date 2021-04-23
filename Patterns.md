_DESIGN PATTERNS_ implemented in Arma project:

- Meyers' Singleton
    - to download the needed files only once
- Factory Method
    - to create various units the types of which are not known in advance
- Composite
    - to compose the units into one army and call war methods not for each 
  individual unit


The Model-View-Controller (MVC) data separation scheme is 
used to interact the game model with the graphics.

___

Reasons for rejecting other patterns:

- Decorator: The color of the player's and enemy's units is a static field
- Command: Actions during the battle do not need to be queued, 
  performed according to a schedule, moreover, the cancel
  operation is also not necessary
- Visitor: The attack methods are executed over the unit abstraction, since the 
  behavior is the same for the entire existing hierarchy
- Chain of Responsibility: The model should not handle diverse requests differently, since 
  each specific request during the battle is known in advance.