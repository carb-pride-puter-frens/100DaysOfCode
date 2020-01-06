# Notes - CSS (Cascading Style Sheets) and Applied Visual Design

## General Notes

- Example of a CSS block

```css
h2 {
    color: red;
}
```

- Use single quotes
- `url()` tag allows for someone to bring in a file/whatever from an external source into the file

## Fonts and Text Properties

- `font-size` is pretty obvious like `color`, it sizes the font
    - Takes in many different values, it will probably be hit on later I assume
    - Pixels, Ems, percentages, etc.. Pretty much any number value, either implicit or explicit
- `font-family` determines the type of font. It can either be a name or a type
    - Name: `Consolas, 'Fira Code'`
        - Single word names don't need quotes, but spaced out names do need single quotes
    - Type: `sans-serif`
- Fonts can either live on the system which the site is hosted or imported in through a link by either adding a `<link>` tag in the HTML or an `@import()` tag in CSS
    - I usually prefer keeping fonts solely in CSS but FCC (freeCodeCamp) wants to use links, which is fine I guess lol
- `Font degredation`: when CSS picks a font when a specified font is not available for usage
    - i.e. `font-family: Lobster, monospace;`
    - If Lobster is available, then it will use that. If not, it will default to monospace
- `text-align` is, given the name, how you want to align the text of an element in a given block
    - Options:
        - `justify`: all lines of text except the last line meet at the left and right edges of the block
        - `center`: center's the text
        - `right`: pushes text to the right
        - `left`: pushes text to the left
    - Essentially, think of these options like the options in Word when it comes to alignment
- You can give text a `height` and `width` value, which just changes how big the block is, not the font size
    - Essentially almost everything is a `div` with some kind of special property, like what text is inside of it
    - Only ones I can think of that doesn't fully follow that is `span` and `img`, which are inline
- Special tags made for stylizing text inside HTML
    - Note: browsers will convert most of these tags to their proper styling in CSS. See the equivalents below
    - `strong`: makes text bold (CSS equivalent: `font-weight: bold;`)
    - `u`: underlines text (CSS equivalent: `text-decoration: underline;`)
        - Avoid using where a link might go since `a` tags use underlines as well unless specified
    - `em`: 'emphasizes' (or pretty much italicizes) text (CSS equivalent: `font-style: italic;`)
        - There used to be a difference between `em` and `i` but most prefer to use `em` in most cases, including those where `i` would have been used in the past
    - `s`: strikethrough text (CSS equivalent: `text-decoration: line-through;`)
    - `hr`: creates a horizontal line through the page (*Does not have a CSS equivalent*)
        - Most people prefer to not use `hr` at all unless totally needed
- `text-transform` will transform the text in an element given the value
    - `lowercase` and `uppercase` work like `toLowerCase()` and `toUpperCase()` in JS
    - `capitalize` will capitalize the first letter of every word
    - `initial` uses the default value
    - `inherit` takes the `text-transform` value of the parent (this works across the board as well, not just this property)
    - `none` does nothing
- `font-weight` defines the weight of the font given a number value (usually 100-900 by 100s [100, 200, 300, etc.])
- `line-height` changes the height of each line of text by any valid unit

## Colors

- `color` changes font/foreground color
    - Takes in either a name, hex value, abbreviated hex value, rgb, rgba, hsb, hsba, etc.
    - Probably will list all of them later
- `background-color` sets the color of the background
    - `background` has properties, but most people just use color
- Total color possibilities: 16mil
- Abbreviated hex for colors (`#f0f` instead of `#ff00ff`) brings possibilities down from 16mil to 4000, but is easier to interpret
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

## Identifiers and Precedence

- `.class` and `#id` are the main usages for identifiers
    - Classes are meant to be used in multiple places
    - IDs are meant to be used in only one place
    - This isn't enforced really, but is good practice
- Instead of classes or ids, you can also use attribute selectors, where CSS will style where the attribute equals the given value
    - ex: `[type=submit]` formats all input values which have the submit type
- Styling the `body` tag will essentially style all elements in the HTML file that are seeable in the page
- Using `html` or the `:root` pseudo-class selector will allow CSS elements to apply to everything in the HTML file
- `*` selects all elements individually, not as a parent like `html`
- Official order of precedence
    - `!important` tag next to a style key/value
    - Inline styles specifically on one element
    - IDs (lowest on page to highest on page)
    - Classes (lowest on page to highest on page)
    - `body` tag (lowest to highest) OR `html` OR (usually) `:root`
    - Attribute selector (lowest to highest)
    - Tag listing (lowest to highest)

## Element Sizing

- `width` determines how wide an element is
    - Uses same semantics as `font-size`, anything that eventually means a number is allowed
- `padding` adjusts the amount of space between the border and the contents of the element
- `margin` adjusts the amount of space between the border and the space surrounding the element
    - A negative `margin` will make the element move out into the space/become bigger
- `margin` and `padding` have properties which edit individual sides of the element: top, right, bottom, left
    - When editing in the same element like `border`, the order goes TRBL (Clockwise Notation). If only two elements are given, then its (TB)(RL)
        - i.e. `margin: 10px 20px 10px 20px;` makes the top margin 10px, right margin 20px, bottom margin 10px, and left margin 20px
        - i.e. `margin: 10px 20px;` is the equivalent of above. The first value makes the top and bottom margin 10px and the left and right margin 20px

## Borders and Box Shadows

- `border` defines a border that goes around an element
    - `border` is one of those special modifiers that can be modified in several ways as it has properties
    - Some of them:
        - `border-color` defines the color of a border
        - `border-width` defines the thickness of a border
        - `border-style` defines the type of border (i.e. solid, dashed, etc.)
        - `border-radius` defines how rounded the border is
            - A radius of `50%` makes the object seem circular
    - Listing each property is not technically needed, but useful in some cases
    - Can be used similarly to `margin` and `padding` where you can provide multiple values in the same time
    - ex: `border: 10x solid black`
- `box-shadow` property: applies one or more shadows to an element
    - can make a box or card pop out on a page more
    - Order of subproperties: `offset-x offset-y [blur-radius [spread-radius [color]]]`
        - `offset` is how far to push the shadow (x is horizontal, y is vertical, is assummed for the rest of the notes)
        - `blur-radius` (*optional*): The larger this value, the bigger the blur, so the shadow becomes bigger and lighter
        - `spread-radius` (*optional*): Positive values will cause the shadow to expand and grow bigger, negative values will cause the shadow to shrink.
        - `color` (*optional*) is the color of the shadow
        - Can put multiple shadows by combining with a comma
        - Tons of different configurations, look at the MDN page [here](https://developer.mozilla.org/en-US/docs/Web/CSS/box-shadow) for more info

## Units of Measurements

- Absolute and Relative Units
    - Absolute units actually tie in to real lengths of measurement
        - i.e. `px`, `in`, `cm`
    - Relative units are relative given the context
        - i.e. `em` refers to the measurement relative to the parent
- These apply anywhere where a size is needed, like `font-size`, `width`, etc.

## Variables/Custom Properties

- Variables, much like in code, hold values that can be used in multiple places
- Syntax: `--name: value;`
- Usage: `color: var(--variable, defaultValueIfVarIsntAvailable);`
- Usage for multiple variables if first var is not available: `color: var(--first-var, var(--second-var, var(--third-var. defaultFallback)));`
    - Cannot list them in one `var()` call as CSS always only checks all values after the first arg
        - They shouldn't, and someone should change that since so many other langauges (***LIKE JS, THE LANGAUGE OF THE WEB IRONICALLY***) don't do this, but whatever
- This seems like a good resource for this: [Mozilla Docs for CSS Variables](https://developer.mozilla.org/en-US/docs/Web/CSS/Using_CSS_custom_properties)
- Best place to put custom variables is the `:root` pseudo-class selector (usually same thing as `html` but may differ on other browsers)
    - Think of `:root` as the place to define global proerties. Mostly will probably just be for vars
- You can overwrite vars in child selectors if needed, with (probably) the same precedence rules listed in these notes
- FCC says you should do fallbacks by putting a similar tag with the fallback value above it for browsers that can't use vars yet
    - Maybe don't cater to 85 year olds that are still running IE 9 or something instead lmao
- Personal note: this feature makes stuff like Sass and Less way less appealing to use since CSS has vars and math now, but I'm still gonna go through Sass and see what they offer

## Media Queries

- Made using `@media`; allow for using different values depending on things like screen-size and others
- Basic CSS I imagine won't go into depth, but Applied Visual Design will
- I've had trouble with media queries in the past, which is one of the major reasons why I mostly relied on Bootstrap and other CSS frameworks

## Visability

- `opacity` is obvious, defines the opacity of an element (takes in 0-1 decimal where 0 is transparent and 1 is fully opaque)

## Positioning and Layering

- Positioning (More info [here](https://developer.mozilla.org/en-US/docs/Web/CSS/position) on MDN)
    - `relative` positioning changes the position of an element based on where it would be if it was positioned normally
        - Changed with the `bottom`, `top`, `left`, and `right` properties which move it so many units ***away*** from the given spot
            - ex: `bottom: 10px; left: 20px;` will move it 10 pixels up and 20 towards the right
        - It doesn't change the normal flow around it, just how it's shown on the screen
        - For accessibility sake, the markup should still read from top to bottom how it should be read. Position should not be used to drastically change where an element is, just slightly. If something is put on top and you position it to the bottom, it's better off for the element to be on the bottom in the markup for screen-reading and other accessibility purposes
    - `absolute` positioning changes the position of an element based on the edges of the containing block (i.e. margins are added to the offsets if they are in the parent block)
        - For this, the normal properties from `relative` are used, except they aren't reversed
    - `fixed` works the same as `absolute`, but it will remain in place on the screen, even when scrolling
    - `sticky` combines both from `relative` and `fixed`. Keeps the element in place like `fixed` but with the same semantics as `relative`
    - Differences
        - `relative` just moves visually and other blocks around it are not affected. `absolute` moves based on the edges of the containing block and will bring other blocks into place with it. `fixed` works similarly to `absolute`, but will keep it sticky to the page
            - MDN link from the title shows a great example of this where three blocks are in a row. In `relative`, where the middle block is given the `position`, the block moves positions freely and doesn't affect the other blocks. In `absolute`, it moves slightly and the third block from the right takes it's place
            - MDN Definitions:
                - `absolute`: The element is removed from the normal document flow, and no space is created for the element in the page layout. It is positioned relative to its closest positioned ancestor, if any; otherwise, it is placed relative to the initial containing block.
                - `relative`: The element is positioned according to the normal flow of the document, and then offset relative to itself based on the values of top, right, bottom, and left. The offset does not affect the position of any other elements; thus, the space given for the element in the page layout is the same as if position were static.
- Floating
    - `float` removes a block from the normal flow and pushes it to the given direction, `left` or `right`
- `z-index` defines the order of layers, so that with two elements, the one with the higher integer value moves to the foreground
- Many ways to center horizontally, especially when we get to grid and flexbox. Another way is to set `margin` to `auto`
