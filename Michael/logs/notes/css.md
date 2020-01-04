# Notes - CSS (Cascading Style Sheets)

## General Notes

- Example of a CSS block

```css
h2 {
    color: red;
}
```

- Use single quotes

## Fonts

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

## Colors

- `color` changes font/foreground color
    - Takes in either a name, hex value, rgb, rgba, hsb, hsba, or other color value
    - Probably will list all of them later
- `background-color` sets the color of the background
    - `background` has properties, but most people just use color

## Identifiers and Precedence

- `.class` and `#id` are the main usages for identifiers
    - Classes are meant to be used in multiple places
    - IDs are meant to be used in only one place
    - This isn't enforced really, but is good practice
    - IDs take precedence over Classes when it comes to overriding styles
    - The lower it is, the higher precendence it takes (if it's the same type)
    - IDs > Classes > Body tag > Other tags
- Instead of classes or ids, you can also use attribute selectors, where CSS will style where the attribute equals the given value
    - ex: `[type=submit]` formats all input values which have the submit type
- Styling the `body` tag will essentially style all elements in the HTML file that are seeable in the page
- Order of precedence


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

## Borders

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

## Units of Measurements

- Absolute and Relative Units
    - Absolute units actually tie in to real lengths of measurement
        - i.e. `px`, `in`, `cm`
    - Relative units are relative given the context
        - i.e. `em` refers to the measurement relative to the parent
- These apply anywhere where a size is needed, like `font-size`, `width`, etc.
