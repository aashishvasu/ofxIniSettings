# ofxIniSettings
openFrameworks addon for providing a simple and straightforward way to manage settings with INI config files.

## Introduction
**`ofxIniSettings`** is built on top of the single header [mINI](https://github.com/pulzed/mINI) c++ library to provide simple reads and writes to INI files. This can be used standalone without any other addon dependency. All variables are stored as `string` types, and conversions exist for the standard c++ types, and a few openFramework specific types (`ofVec2f, 3f, 4f, ofColor`).

## Installation
Either clone or download the code into the `openFrameworks/addons/` folder. Then you can use the OF Project Generator to add this addon to your project.

## Usage
[WIP]
### Example
Open the [`/example-simple`](/example-simple/) directory for a simple example that loads an ini file and writes changes to console.

## Documentation
Documentation is generated using [Natural Docs](https://naturaldocs.org/). Clone or download the repository and open [`/docs/index.html`](/docs/index.html) to find class and function documentation.

## Known issues
[WIP]

## Why did I make this?
openFrameworks by default only has an interface to save a settings file in the `.xml` format. In my opinion, although any plaintext format is as good as the next in terms of programmatically reading and writing to a file, making the file human-readable is another thing altogether. Trying to read XML files really hurts the eyes and possibly the brain.

Here are some quick comparisons of the same set of parameters setup in 3 different formats:

**`XML`**

```xml
<!-- Information-->
<stats>
	<name>HoLee Schitt</name>
	<height>183</height>
	<ishungry>false</ishungry>
</stats>
```

**`JSON`**
```json
{
"comment":"Information",
"stats":
	{
		"name":"HoLee Schitt",
		"height":"183",
		"ishungry":"false"
	}
}
```

**`INI`**
```ini
; Information
[stats]
name = HoLee Schitt
height = 183
ishungry = false
```

I definitely find that INI is much more human readable. It does come with certain tradeoffs like not being able to make nested sections, but those are easily fixed by adding something like your own dot syntax:
```ini
[parentsection]
parameter = 0

[parentsection.childsection1]
parameter = 0

[parentsection.childsection2]
parameter = 0
```

In the context of creating an interface for settings, I find it more than adequate for the job. I won't go so far as to claim that it is the defacto standard for storing any kind of configuration data, but its damn close to it.
## License
`ofxIniSettings` is available under the [MIT License](/license.md).

## Contributing
If you want to contribute to this (admittedly tiny) addon, [fork the repo](https://docs.github.com/en/get-started/quickstart/fork-a-repo) and create a pull request with your changes.
Make sure you update documentation in your PR before sending.

## Credits
* [pulzed](https://github.com/pulzed) - mINI
