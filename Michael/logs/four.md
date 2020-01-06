# Day 4 - (1/5/2020)

Time Spent: 1 hour

## FreeCodeCamp

- Continued work on Applied Visual Design
    - Started: Learn About Complementary Colors
    - Ended: Create Texture by Adding a Subtle Pattern as a Background Image

## Notes

- Color theory
    - Two colors which are complementary have both of their RGB values in which adding them reaches 255
        - Ex: Red (rgb(255,0,0)) and Cyan (rgb(0,255,255))
    - Tertiary colors: the result of combining a primary color with one of its secondary color neighbors
        - The combination of Red/Green/Blue with Yellow(R+G), Cyan(G+B), or Magenta(R+B)
        - ex: Orange is the combination of primary color Red and secondary neighbor Yellow
        - Color wheel: ![color wheel](https://static-cse.canva.com/_next/static/assets/complementary-colors.1200x690.f6aff61a6d4a050896d92666ac184888.png)
- CSS3 `hsl()`: allows for defining colors by their hue, saturation, and lightness
    - Hue: essentially color. 0-360 where a color lands on a line where the integer value is
    - Saturation: the percentage of gray in a color. 100% has no gray but 0% is fully gray
    - Lightness: amount of black/white in a color. 0% is black and 100% is white
    - Adjusting the saturation and lightness of a hue allows to create different tones of a color
- Gradients
    - Most basic one is a linear gradient, which defines a `gradient_direction` then a list of colors in the gradient
        - `linear-gradient(direction (#deg), ...colors)` (this is the only one where lists are allowed I guess)
        - it nice
    - Repeating linear gradient: same as linear gradient, but with extra args to include measurement units alongside colors
        - `repeating-linear-gradient(direction (#deg), ...colors measurement);`
        - eh
- `url()` tag allows for someone to bring in a file/whatever from an external source into the file

## Personal Notes (if any)

- Colors are neat, learned a bunch about that
- Yep lol
