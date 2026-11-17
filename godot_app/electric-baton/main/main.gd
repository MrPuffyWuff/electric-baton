extends Node2D

var pitch_to_rect : Dictionary[int, ColorRect] = {}

func _ready() -> void:
	OS.open_midi_inputs()
	print(OS.get_connected_midi_inputs())
	for p in range(36, 84 + 1):
		var rect : ColorRect = ColorRect.new()
		var percent : float = (p-36.0)/(85.0-36)
		rect.position = Vector2(percent * 960,0)
		rect.size = Vector2(960/(85-36),0)
		rect.color = Color(percent,1.0,1.0)
		pitch_to_rect[p] = rect
		add_child(rect)

func _input(input_event):
	if input_event is InputEventMIDI:
		#_print_midi_info(input_event)
		pitch_to_rect[input_event.pitch].size.y = input_event.velocity

func _print_midi_info(midi_event : InputEventMIDI):
	print(midi_event)
	print("Channel ", midi_event.channel)
	print("Message ", midi_event.message)
	print("Pitch ", midi_event.pitch)
	print("Velocity ", midi_event.velocity)
	print("Instrument ", midi_event.instrument)
	print("Pressure ", midi_event.pressure)
	print("Controller number: ", midi_event.controller_number)
	print("Controller value: ", midi_event.controller_value)
	
