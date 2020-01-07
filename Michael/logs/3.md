# Day 3 - (1/4/2020)

Time Spent: ~3-4 hours

## GitHub

- Updated Day 2 log with yesterday's notes

## FreeCodeCamp

- Finished the rest of Basic CSS
- Started Applied Visual Design (aka Intermediate/Advanced CSS)
    - Start: Create Visual Balance Using the text-align Property
    - End: Center an Element Horizontally Using the margin Property

## Notes - Basic CSS

- Official order of precedence
    - `!important` tag next to a style key/value
    - Inline styles specifically on one element
    - IDs (lowest on page to highest on page)
    - Classes (lowest on page to highest on page)
    - `body` tag (lowest to highest) OR `html` OR (usually) `:root`
    - Attribute selector (lowest to highest)
    - Tag listing (lowest to highest)
- Abbreviated hex for colors (`#f0f` instead of `#ff00ff`) brings possibilities down from 16mil to 4000, but is easier to interpret
- Variables/Custom Properties
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
- Media queries
    - Made using `@media`; allow for using different values depending on things like screen-size and others
    - Basic CSS I imagine won't go into depth, but Applied Visual Design will
    - I've had trouble with media queries in the past, which is one of the major reasons why I mostly relied on Bootstrap and other CSS frameworks

## Notes - Applied Visual Design

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
- `box-shadow` property: applies one or more shadows to an element
    - can make a box or card pop out on a page more
    - Order of subproperties: `offset-x offset-y [blur-radius [spread-radius [color]]]`
        - `offset` is how far to push the shadow (x is horizontal, y is vertical, is assummed for the rest of the notes)
        - `blur-radius` (*optional*): The larger this value, the bigger the blur, so the shadow becomes bigger and lighter
        - `spread-radius` (*optional*): Positive values will cause the shadow to expand and grow bigger, negative values will cause the shadow to shrink.
        - `color` (*optional*) is the color of the shadow
        - Can put multiple shadows by combining with a comma
        - Tons of different configurations, look at the MDN page [here](https://developer.mozilla.org/en-US/docs/Web/CSS/box-shadow) for more info
- `opacity` is obvious, defines the opacity of an element (takes in 0-1 decimal where 0 is transparent and 1 is fully opaque)
- `text-transform` will transform the text in an element given the value
    - `lowercase` and `uppercase` work like `toLowerCase()` and `toUpperCase()` in JS
    - `capitalize` will capitalize the first letter of every word
    - `initial` uses the default value
    - `inherit` takes the `text-transform` value of the parent (this works across the board as well, not just this property)
    - `none` does nothing
- `font-weight` defines the weight of the font given a number value (usually 100-900 by 100s [100, 200, 300, etc.])
- `line-height` changes the height of each line of text by any valid unit
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

## Personal Notes

- I might add something that notifies a person if they didn't do a day just for reminder's sake, because I'll probably forget a day for sure
    - Might have to happen if I ever get to the Discord bot section. Or maybe there is a GitHub action I can make
- I did a lot today lol. Got Basic CSS done, now onto theory about design and some other properties
    - I remember seeing some stuff about a lot of it still, so I'm not in fully unrecognizable territory just yet
- I remember not understanding what `position` does at all, now a lot of it makes sense, so yay for that lol
- Tomorrow is a lot about color theory as well as some other stuff. After this section I'm gonna take a stab at making the tribute page because that seems not super complicated, then I can focus on accessibility and other design in which I can use to improve the page
