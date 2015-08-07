w = world_create(600, 400, 10, 30, 44100)
SHAPE_RECT = 0

m = matter_create()
life(m, 7)
size(m, 200, 400)
anchor(m, 0, 0)
pos(m, 233, 0)
act(m, 0, shape(7.0, SHAPE_RECT, 0x66ccff, 255))
act(m, 0, fade_in(2.0))
populate(w, m, 2, 1)

m = matter_create()
life(m, 5)
size(m, 300, 200)
pos(m, 300, 200)
act(m, 0, video_clip('xx.mp4', 3, 5))
act(m, 2, ease_cubic_in(transition_erase_l(0.5, 0)))
act(m, 3, ease_cubic_out(transition_erase_l(0.5, 255)))
populate(w, m, 0, 10)

wv = wave_create()
life_w(wv, 10)
play(wv, 0, audio_clip('xx.mp3', 185, 10))
play(wv, 0, reverse_w(10))
clang(w, wv, 0)

write(w, 'output.mp4')
